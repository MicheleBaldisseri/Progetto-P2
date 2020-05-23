#include "appunwindow.h"


AppunWindow::AppunWindow(QWidget *parent, const QDate &selDate, DatiEvento* e): QDialog(parent), date(selDate)
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

    modifica=false;
    if(e){ //se viene passato un evento, allora e' una modifica e setto il form
        setForm(e);
        modifica=true;
    }
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
    else if(obj->titolo.find('|') || obj->luogo.find('|')){
        QMessageBox::warning(this,"Input non valido","Impossibile usare il carattere speciale '|'");
    }else
        emit eventoInserito(obj,modifica);
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
    colorChoise->addItem("Bianco");
    colorChoise->addItem("Rosso");
    colorChoise->addItem("Verde - predefinito");
    colorChoise->addItem("Giallo");
    colorChoise->addItem("Arancione");
    colorChoise->addItem("Nero");
    colorChoise->addItem("Blu");
    colorChoise->addItem("Viola");
    colorChoise->addItem("Grigio");

    //setta il selezionato di default
    colorChoise->setCurrentIndex(2);

    QColor orangeColor(255,165,0);
    colorChoise->setItemData( 7, QColor( Qt::magenta ), Qt::TextColorRole );
    colorChoise->setItemData( 3, QColor( Qt::yellow), Qt::TextColorRole );
    colorChoise->setItemData( 1, QColor( Qt::red ), Qt::TextColorRole );
    colorChoise->setItemData( 2, QColor( Qt::green ), Qt::TextColorRole );
    colorChoise->setItemData( 6, QColor( Qt::cyan ), Qt::TextColorRole );
    colorChoise->setItemData( 0, QColor( Qt::white ), Qt::TextColorRole );
    colorChoise->setItemData( 4, orangeColor, Qt::TextColorRole );
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

void AppunWindow::setForm(DatiEvento* obj){
    setTimeBegin->setTime(obj->inizio);
    title->setText(QString::fromStdString(obj->titolo));
    colorChoise->setCurrentIndex(obj->colore);
    setTimeEnd->setTime(obj->fine);
    location->setText(QString::fromStdString(obj->luogo));
}
