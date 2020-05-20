#include "compwindow.h"

CompWindow::CompWindow(QWidget *parent, const QDate &selDate): QDialog(parent), date(selDate)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta"));

    //allestimento finestra
    addCompItems();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    //solo se l'inserimento è confermato l'evento viene creato
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Compleanno"));

    setMinimumSize(280,150);
}

CompWindow::~CompWindow(){}

void CompWindow::creaEvento()
{
    //inserimento dati passati dall'utente
    DatiEvento* obj= new DatiEvento;
    obj->type=2; //2=compleanno
    obj->titolo=title->text().toStdString();
    obj->colore=colorChoise->currentIndex();
    obj->dataSelezionata=date;
    obj->annoNascita=setYear->value();

    emit eventoInserito(obj);
}

void CompWindow::addCompItems()
{
    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);

    colorChoise= new QComboBox(this);
    title= new QLineEdit(this);
    setYear= new QSpinBox(this);
    setYear->setRange(0, 2100);

    //aggiunta degli elementi nel layout
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);
    layout->addRow(new QLabel(tr("Anno di nascita:")), setYear);

    //inserimento elementi nella comboBox e settaggio colori
    colorChoise->addItem("Arancione - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Grigio");
    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 6, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 3, QColor( Qt::green ), Qt::TextColorRole );
    colorChoise->setItemData( 4, QColor( Qt::cyan ), Qt::TextColorRole );
    colorChoise->setItemData( 5, QColor( Qt::white ), Qt::TextColorRole );
    colorChoise->setItemData( 0, orangeColor, Qt::TextColorRole );
    colorChoise->setItemData( 8, QColor( Qt::gray ), Qt::TextColorRole );

    formGroupBox->setLayout(layout);
}
