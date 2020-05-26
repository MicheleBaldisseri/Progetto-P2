#include "compwindow.h"

CompWindow::CompWindow(QWidget *parent, const QDate &selDate, DatiEvento* e): QDialog(parent), date(selDate)
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

    setFixedSize(280,150);

    modifica=false;
    if(e){ //se viene passato un evento, allora e' una modifica e setto il form
        setForm(e);
        modifica=true;
    }
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

    if(obj->titolo.find('|')!= std::string::npos){
            QMessageBox::warning(this,"Input non valido","Impossibile usare il carattere speciale '|'");
    }else
        emit eventoInserito(obj,modifica);
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
    layout->addRow(new QLabel(tr("Nome:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);
    layout->addRow(new QLabel(tr("Anno di nascita:")), setYear);

    //inserimento elementi nella comboBox e settaggio colori
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Arancione - pred.");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Grigio");

    //setta il selezionato di default
    colorChoise->setCurrentIndex(4);

    formGroupBox->setLayout(layout);

}

void CompWindow::setForm(DatiEvento* obj){
    title->setText(QString::fromStdString(obj->titolo));
    colorChoise->setCurrentIndex(obj->colore);
    setYear->setValue(obj->annoNascita);
}
