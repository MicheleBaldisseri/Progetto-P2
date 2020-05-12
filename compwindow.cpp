#include "compwindow.h"

CompWindow::CompWindow(QWidget *parent): QDialog(parent)
{
    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta"));

    addCompItems();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Compleanno"));
}

CompWindow::~CompWindow()
{

}

void CompWindow::addCompItems()
{
    QFormLayout *layout = new QFormLayout;
    QComboBox* colorChoise= new QComboBox(this);
    QLineEdit* title= new QLineEdit(this);
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);

    colorChoise->addItem("Arancione - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Verde");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Grigio");

    QDateEdit* setDate= new QDateEdit(this);
    layout->addRow(new QLabel(tr("Data di nascita:")), setDate);

    formGroupBox->setLayout(layout);
}
