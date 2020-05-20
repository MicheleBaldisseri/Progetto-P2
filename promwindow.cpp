#include "promwindow.h"

PromWindow::PromWindow(QWidget *parent, const QDate &selDate): QDialog(parent), date(selDate)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta promemoria"));

    //allestimento della finestra
    addPromItems();
    bigEditor = new QPlainTextEdit(this);
    bigEditor->setFixedHeight(100);
    bigEditor->setPlainText(tr("Inserisci qui la descrizione... "));
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    //solo se l'inserimento è confermato l'evento viene creato
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(bigEditor);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Promemoria"));

    setMinimumSize(280,250);
}

PromWindow::~PromWindow(){}

void PromWindow::creaEvento()
{
    //inserimento dati passati dall'utente
    DatiEvento* obj= new DatiEvento;
    obj->contenuto=bigEditor->toPlainText().toStdString();
    obj->inizio=setTime->time();
    obj->titolo=title->text().toStdString();
    obj->dataSelezionata=date;
    obj->colore=colorChoise->currentIndex();
    obj->type=0;//0=promemoria

    //controllo per evitare di inserire promemoria in date passate
    if(date < QDate::currentDate())
        QMessageBox::warning(this,"Input non valido","Impossibile inserire un promemoria in una data precedente a quella corrente.");
    else
        emit eventoInserito(obj);
}

void PromWindow::addPromItems()
{

    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);

    //creazione elementi
    colorChoise= new QComboBox(this);
    title= new QLineEdit(this);
    setTime= new QTimeEdit(this);

    //inserimento nel layout
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);
    layout->addRow(new QLabel(tr("Orario:")), setTime);

    //inserimento elementi nella comboBox e settaggio colori

    colorChoise->addItem("Bianco");
    colorChoise->addItem("Rosso - predefinito");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Grigio");

    //setta il selezionato di default
    colorChoise->setCurrentIndex(1);

    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 7, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 3, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::green ), Qt::TextColorRole );
    colorChoise->setItemData( 6, QColor( Qt::cyan ), Qt::TextColorRole );
    colorChoise->setItemData( 0, QColor( Qt::white ), Qt::TextColorRole );
    colorChoise->setItemData( 4, orangeColor, Qt::TextColorRole );
    colorChoise->setItemData( 8, QColor( Qt::gray ), Qt::TextColorRole );

    formGroupBox->setLayout(layout);
}
