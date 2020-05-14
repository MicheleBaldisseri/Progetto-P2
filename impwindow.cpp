#include "impwindow.h"


ImpWindow::ImpWindow(QWidget *parent) : QDialog(parent)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta impegno"));
    RicorrenzaGroupBox= new QGroupBox(tr("Ripeti"));

    addImpItems();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(RicorrenzaGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Impegno"));

    setMinimumSize(300,300);
}

ImpWindow::~ImpWindow()
{

}

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

void ImpWindow::addImpItems()
{
    //layout del box informazioni generali
    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);
    //layout del box per settare ricorrenze
    QFormLayout *layoutR = new QFormLayout;
    layoutR->setContentsMargins(10,18,10,10);
    //lista dei colori
    QComboBox* colorChoise= new QComboBox(this);
    QLineEdit* title= new QLineEdit(this);

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

    //orario di inizio e fine
    QTimeEdit* setTimeBegin= new QTimeEdit(this);
    QTimeEdit* setTimeEnd= new QTimeEdit(this);
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
    //imposto layout
    formGroupBox->setLayout(layout);

    ricChoise= new QComboBox(this);
    ricChoise->addItem("Giorni");
    ricChoise->addItem("Settimane");
    ricChoise->addItem("Mesi");

    intGiorni= new QSpinBox(this);
    intGiorni->setRange(1, 20);
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

    layoutR->addRow(rip);

    QCheckBox* flag= new QCheckBox("Inserisci manualmente",this);
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

    RicorrenzaGroupBox->setLayout(layoutR);

    QObject::connect(flag, SIGNAL(clicked(bool)), this, SLOT(inserisciManualmente(bool)));

}
