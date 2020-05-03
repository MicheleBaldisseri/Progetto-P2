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
}

ImpWindow::~ImpWindow()
{

}

void ImpWindow::addImpItems()
{
    //layout del box informazioni generali
    QFormLayout *layout = new QFormLayout;
    //layout del box per settare ricorrenze
    QFormLayout *layoutR = new QFormLayout;
    //lista dei colori
    QComboBox* colorChoise= new QComboBox;
    QLineEdit* title= new QLineEdit;
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
    QTimeEdit* setTimeBegin= new QTimeEdit;
    QTimeEdit* setTimeEnd= new QTimeEdit;
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

    QComboBox* ricChoise= new QComboBox;
    layoutR->addRow(new QLabel(tr("Ogni:")), ricChoise);
    ricChoise->addItem("Giorno");
    ricChoise->addItem("Settimana");
    ricChoise->addItem("Mese");
    QCheckBox* flag= new QCheckBox("Inserisci manualmente");
    layoutR->addRow(flag);
    QDateTimeEdit* n1= new QDateTimeEdit;
    QDateTimeEdit* n2= new QDateTimeEdit;
    QDateTimeEdit* n3= new QDateTimeEdit;
    layoutR->addRow(new QLabel(tr("Ricorrenza 1:")), n1);
    layoutR->addRow(new QLabel(tr("Ricorrenza 2:")), n2);
    layoutR->addRow(new QLabel(tr("Ricorrenza 3:")), n3);
    RicorrenzaGroupBox->setLayout(layoutR);

}
