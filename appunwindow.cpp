#include "appunwindow.h"


AppunWindow::AppunWindow()
{

    createFormGroupBox();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);


    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);


    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Appuntamento"));
}

void AppunWindow::createFormGroupBox()
{

    formGroupBox = new QGroupBox(tr("Imposta appuntamento"));
    QFormLayout *layout = new QFormLayout;
    QComboBox* colorChoise= new QComboBox;
    QLineEdit* title= new QLineEdit(this);
    QLineEdit* location= new QLineEdit(this);
    //titolo, luogo, tendina colori
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Luogo:")), location);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);
    //lista dei colori
    colorChoise->addItem("Verde - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Viola");
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
}
