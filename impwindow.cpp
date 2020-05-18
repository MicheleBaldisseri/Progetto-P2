#include "impwindow.h"
#include <iostream>

ImpWindow::ImpWindow(QWidget *parent, QDate &selDate) : QDialog(parent), date(selDate)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta impegno"));
    //RicorrenzaGroupBox= new QGroupBox(tr("Ripeti"));

    addImpItems();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    mainLayout->addWidget(formGroupBox);
    //mainLayout->addWidget(RicorrenzaGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Impegno"));

    setMinimumSize(300,150);
}

ImpWindow::~ImpWindow(){}
/*
void ImpWindow::inserisciManualmente(bool checked)
{
    if(checked){
        n1->setEnabled(true);
        n2->setEnabled(true);
        n3->setEnabled(true);
        ricChoise->setEnabled(false);
        intGiorni->setEnabled(false);
        intOcc->setEnabled(false);
    }
    else{
        n1->setEnabled(false);
        n2->setEnabled(false);
        n3->setEnabled(false);
        ricChoise->setEnabled(true);
        intGiorni->setEnabled(true);
        intOcc->setEnabled(true);
    }
}
*/
void ImpWindow::creaEvento()
{
    DatiEvento* obj= new DatiEvento;
    obj->type=3; //3=impegno
    obj->titolo=title->text().toStdString();
    obj->colore=colorChoise->currentIndex();
    obj->inizio=setTimeBegin->time();
    obj->fine=setTimeEnd->time();
    obj->dataSelezionata=date;
/*
    //inserimento manuale
    if(flag->isChecked()){
        //se ne utilizzo solo 1??
        obj->ricorrenze.push_back(n1->date());
        obj->ricorrenze.push_back(n2->date());
        obj->ricorrenze.push_back(n3->date());
    }
    //inserimento automatico
    else{
        obj->ogni=intOcc->value();
        obj->tipo=ricChoise->currentIndex();
        //tolgo l'evento base
        obj->per=intGiorni->value()-1;
    }
*/
    obj->ogni=intOcc->value();
    obj->tipo=ricChoise->currentIndex();
    //tolgo l'evento base
    obj->per=intGiorni->value()-1;

    if(obj->fine < obj->inizio)
        QMessageBox::warning(this,"Input non valido","Errore: l'orario d'inizio non può essere inferiore a quello finale.");
    /*
    else if(flag->isChecked() && ((n1->date() < date) || (n2->date() < date) || (n3->date() < date)))
        QMessageBox::warning(this,"Input non valido","Errore: la ricorrenza non si può verificare prima della data selezionata.");
        */
    else
        emit eventoInserito(obj);
}

void ImpWindow::addImpItems()
{
    //layout del box informazioni generali
    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);
    //layout del box per settare ricorrenze
    //QFormLayout *layoutR = new QFormLayout;
   // layoutR->setContentsMargins(10,18,10,10);
    //tendina dei colori
    colorChoise= new QComboBox(this);
    //titolo impegno
    title= new QLineEdit(this);

    //aggiungo titolo, tendina colori
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);

    //riempio lista dei colori
    colorChoise->addItem("Viola - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Grigio");
    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 0, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 3, QColor( Qt::green ), Qt::TextColorRole );
    colorChoise->setItemData( 4, QColor( Qt::cyan ), Qt::TextColorRole );
    colorChoise->setItemData( 5, QColor( Qt::white ), Qt::TextColorRole );
    colorChoise->setItemData( 6, orangeColor, Qt::TextColorRole );
    colorChoise->setItemData( 8, QColor( Qt::gray ), Qt::TextColorRole );

    //orario di inizio e fine
    setTimeBegin= new QTimeEdit(this);
    setTimeEnd= new QTimeEdit(this);
    QHBoxLayout* time= new QHBoxLayout;
    QLabel* begin= new QLabel(tr("Orario inizio:"));
    QLabel* end= new QLabel(tr("Orario fine:"));

    //inserisco nel Hlayout
    time->addWidget(begin);
    time->addWidget(setTimeBegin);
    time->addWidget(end);
    time->addWidget(setTimeEnd);
    //inserisco nel form
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
/*
    //check inserimento manuale
    flag= new QCheckBox("Inserisci manualmente",this);
    layoutR->addRow(flag);

    n1= new QDateEdit(this);
    n2= new QDateEdit(this);
    n3= new QDateEdit(this);

    n1->setEnabled(false);
    n2->setEnabled(false);
    n3->setEnabled(false);

    layoutR->addRow(new QLabel(tr("Ricorrenza 1:")), n1);
    layoutR->addRow(new QLabel(tr("Ricorrenza 2:")), n2);
    layoutR->addRow(new QLabel(tr("Ricorrenza 3:")), n3);

    //o inserisco le ricorrenze manualmente, o periodicamente in automatico
    QObject::connect(flag, SIGNAL(clicked(bool)), this, SLOT(inserisciManualmente(bool)));

    RicorrenzaGroupBox->setLayout(layoutR);
    */
}
