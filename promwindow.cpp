#include "promwindow.h"

PromWindow::PromWindow(QWidget *parent, const QDate &selDate): QDialog(parent), date(selDate)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta promemoria"));

    addPromItems();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("Inserisci qui la descrizione... "));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(bigEditor);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Promemoria"));

    setMinimumSize(280,250);
}

PromWindow::~PromWindow()
{

}

void PromWindow::creaEvento()
{
    DatiEvento* obj= new DatiEvento;
    obj->contenuto=bigEditor->toPlainText().toStdString();
    obj->inizio=setTime->time();
    obj->titolo=title->text().toStdString();
    obj->dataSelezionata=date;
    obj->colore=colorChoise->currentIndex();
    obj->type=0;//0=promemoria

    if(date < QDate::currentDate())
        QMessageBox::warning(this,"Input non valido","Impossibile inserire un promemoria in una data precedente a quella corrente.");
    else
        emit eventoInserito(obj);
}

void PromWindow::addPromItems()
{

    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);
    colorChoise= new QComboBox(this);
    title= new QLineEdit(this);
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);

    colorChoise->addItem("Rosso - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Grigio");
    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 3, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 0, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::green ), Qt::TextColorRole );
    colorChoise->setItemData( 4, QColor( Qt::cyan ), Qt::TextColorRole );
    colorChoise->setItemData( 5, QColor( Qt::white ), Qt::TextColorRole );
    colorChoise->setItemData( 6, orangeColor, Qt::TextColorRole );
   // colorChoise->setItemData( 7, QColor( Qt::black ), Qt::TextColorRole );
    colorChoise->setItemData( 8, QColor( Qt::gray ), Qt::TextColorRole );

    setTime= new QTimeEdit(this);
    layout->addRow(new QLabel(tr("Orario:")), setTime);

    formGroupBox->setLayout(layout);
}
