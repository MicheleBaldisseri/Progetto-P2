#include "impwindow.h"
#include <iostream>

ImpWindow::ImpWindow(QWidget *parent, const QDate &selDate, DatiEvento* e) : QDialog(parent), date(selDate)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta impegno"));

    //allestimento finestra
    addImpItems();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    //solo se l'inserimento è confermato l'evento viene creato
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Impegno"));

    setFixedSize(340,170);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    modifica=false;
    if(e){ //se viene passato un evento, allora e' una modifica e setto il form
        setForm(e);
        modifica=true;
    }
}

ImpWindow::~ImpWindow(){}

void ImpWindow::creaEvento()
{
    DatiEvento* obj= new DatiEvento;
    obj->type=3; //3=impegno
    obj->titolo=title->text().toStdString();
    obj->colore=colorChoise->currentIndex();
    obj->inizio=setTimeBegin->time();
    obj->fine=setTimeEnd->time();
    obj->dataSelezionata=date;
    obj->ogni=intOcc->value();
    obj->tipo=ricChoise->currentIndex();
    //tolgo l'evento base
    obj->per=intGiorni->value()-1;

    //controllo sul range di orario inserito
    if(obj->fine < obj->inizio)
        QMessageBox::warning(this,"Input non valido","Errore: l'orario d'inizio non può essere inferiore a quello finale.");
    else if(obj->titolo.find('|')!= std::string::npos){
        QMessageBox::warning(this,"Input non valido","Impossibile usare il carattere speciale '|'");
    }else
        emit eventoInserito(obj,modifica);
}

void ImpWindow::addImpItems()
{
    //layout del box informazioni generali
    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);

    colorChoise= new QComboBox(this);
    title= new QLineEdit(this);
    setTimeBegin= new QTimeEdit(this);
    setTimeEnd= new QTimeEdit(this);

    //aggiungo degli elementi nel layout
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);

    //inserimento elementi nella comboBox e settaggio colori
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Viola - predefinito");
    colorChoise->addItem("Grigio");

    //setta il selezionato di default
    colorChoise->setCurrentIndex(7);

    QHBoxLayout* time= new QHBoxLayout;

    QLabel* begin= new QLabel(tr("Orario inizio:"));
    QLabel* end= new QLabel(tr("Orario fine:"));
    //inserimento nel Hlayout
    time->addWidget(begin);
    time->addWidget(setTimeBegin);
    time->addWidget(end);
    time->addWidget(setTimeEnd);
    //inserimento nel form
    layout->addRow(time);

    //selettore ricorrenze
    ricChoise= new QComboBox(this);
    ricChoise->addItem("Giorni");
    ricChoise->addItem("Settimane");
    ricChoise->addItem("Mesi");

    intGiorni= new QSpinBox(this);
    intGiorni->setRange(2, 20);
    intGiorni->setSingleStep(1);
    intGiorni->setValue(1);
    intOcc=new QSpinBox(this);
    intOcc->setRange(1,9);
    intOcc->setSingleStep(1);
    intOcc->setValue(1);

    QLabel* ogni= new QLabel(tr("Ogni:"));
    QLabel* per= new QLabel(tr("per:"));

    QHBoxLayout* rip= new QHBoxLayout;
    rip->addWidget(ogni);
    rip->addWidget(intOcc);
    rip->addWidget(ricChoise);
    rip->addWidget(per);
    rip->addWidget(intGiorni);

    layout->addRow(rip);
    //imposto layout
    formGroupBox->setLayout(layout);
}

void ImpWindow::setForm(DatiEvento *obj){
    setTimeBegin->setTime(obj->inizio);
    title->setText(QString::fromStdString(obj->titolo));
    colorChoise->setCurrentIndex(obj->colore);
    setTimeEnd->setTime(obj->fine);
}
