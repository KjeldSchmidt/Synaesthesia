#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow( QWidget *parent ) :
	QMainWindow( parent ),
	ui( new Ui::MainWindow )
{
	ui->setupUi( this );
	QWidget *widget = new QWidget;
	setCentralWidget( widget );

	QWidget *topFiller = new QWidget;
	topFiller->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	QLabel *infoLabel = new QLabel( tr("<i>Choose a menu option") );
	infoLabel->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );
	infoLabel->setAlignment( Qt::AlignCenter );

	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin( 5 );
	layout->addWidget( topFiller );
	layout->addWidget(infoLabel);
	widget->setLayout(layout);

	createActions();
	createMenus();

	statusBar()->showMessage( tr("Status") );
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::createActions() {
	closeAct = new QAction ( tr("&Close"), this );
	closeAct->setShortcut(QKeySequence::Close);
	closeAct->setStatusTip( tr("Close the program") );
	connect( closeAct, &QAction::triggered, this, &MainWindow::close );


	aboutAct = new QAction( tr("&About"), this );
	aboutAct->setStatusTip( tr("Information about the program") );
	connect( aboutAct, &QAction::triggered, this, &MainWindow::about );
}

void MainWindow::createMenus() {
	fileMenu = menuBar()->addMenu( tr("&File") );
	fileMenu->addAction( closeAct );

	helpMenu = menuBar()->addMenu( tr("&Help") );
	helpMenu->addAction( aboutAct );
}

void MainWindow::close() {

}

void MainWindow::about() {

}
