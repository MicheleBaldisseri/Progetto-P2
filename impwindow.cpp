#include "impwindow.h"
#include <iostream>

ImpWindow::ImpWindow(QWidget *parent, const QDate &selDate) : QDialog(parent), date(selDate)
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

    setMinimumSize(300,150);
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
    else
        emit eventoInserito(obj);
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
