#include "promwindow.h"

PromWindow::PromWindow(QWidget *parent): QDialog(parent){

    mainLayout = new QVBoxLayout;
    formGroupBox = new QGroupBox(tr("Imposta promemoria"));

    addPromItems();

    bigEditor = new QTextEdit;
    bigEditor->setPlainText(tr("Inserisci qui la descrizione... "));

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(bigEditor);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Promemoria"));
}

PromWindow::~PromWindow()
{

}

void PromWindow::addPromItems()
{

    QFormLayout *layout = new QFormLayout;
    QComboBox* colorChoise= new QComboBox(this);
    QLineEdit* title= new QLineEdit(this);
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

    QTimeEdit* setTime= new QTimeEdit(this);
    layout->addRow(new QLabel(tr("Orario:")), setTime);

    formGroupBox->setLayout(layout);
}
