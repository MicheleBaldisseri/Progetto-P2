#include "appunwindow.h"


AppunWindow::AppunWindow(QWidget *parent, const QDate &selDate): QDialog(parent), date(selDate)
{
    //allestimento del form
    createFormGroupBox();

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    //solo se l'inserimento è confermato l'evento viene creato
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(creaEvento()));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(formGroupBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    setWindowTitle(tr("Appuntamento"));

    setMinimumSize(280,180);
}

AppunWindow::~AppunWindow(){}

void AppunWindow::creaEvento()
{
    //inserimento dati passati dall'utente
    DatiEvento* obj= new DatiEvento;
    obj->type=1; //1=appuntamento
    obj->titolo=title->text().toStdString();
    obj->colore=colorChoise->currentIndex();
    obj->inizio=setTimeBegin->time();
    obj->fine=setTimeEnd->time();
    obj->luogo=location->text().toStdString();
    obj->dataSelezionata=date;

    //controllo sul range di orario inserito
    if(obj->fine < obj->inizio)
        QMessageBox::warning(this,"Input non valido","Errore: l'orario d'inizio non può essere inferiore a quello finale.");
    else
        emit eventoInserito(obj);
}

void AppunWindow::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Imposta appuntamento"));

    QFormLayout *layout = new QFormLayout;
    layout->setContentsMargins(10,18,10,10);

    colorChoise= new QComboBox(this);
    title= new QLineEdit(this);
    location= new QLineEdit(this);

    //aggiunta degli elementi nel layout
    layout->addRow(new QLabel(tr("Titolo:")), title);
    layout->addRow(new QLabel(tr("Luogo:")), location);
    layout->addRow(new QLabel(tr("Colore:")), colorChoise);

    //inserimento elementi nella comboBox e settaggio colori
    colorChoise->addItem("Verde - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Grigio");
    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 3, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 0, QColor( Qt::green ), Qt::TextColorRole );
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
    //imposto layout
    formGroupBox->setLayout(layout);
}
