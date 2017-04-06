#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow( QWidget *parent ) :	QMainWindow( parent ), ui( new Ui::MainWindow )
{
	ui->setupUi( this );
	QWidget *mainWidget = new QWidget;
	this->setCentralWidget( mainWidget );

	QWidget *toolBar = new QWidget;
	toolBar->setMinimumHeight( 30 );
	toolBar->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Minimum );
	toolBar->setStyleSheet("background-color: green");

	QWidget *projectOverviewPanel = new QWidget;
	projectOverviewPanel->setMinimumWidth( 100 );
	projectOverviewPanel->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::Expanding );
	projectOverviewPanel->setStyleSheet("background-color: red");

	QWidget *mainEditArea = new QWidget;
	mainEditArea->setMinimumSize( QSize( 300, 200 ) );
	mainEditArea->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	mainEditArea->setStyleSheet("background-color: blue");

	QSplitter *editArea = new QSplitter( this );
	editArea->addWidget( projectOverviewPanel );
	editArea->addWidget( mainEditArea );
	editArea->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	editArea->setChildrenCollapsible( false );

	QVBoxLayout *layout = new QVBoxLayout;
	layout->setMargin( 5 );
	layout->addWidget( toolBar );
	layout->addWidget( editArea );
	mainWidget->setLayout( layout );

	createActions();
	createMenus();

	statusBar()->showMessage( tr("Status") );
	this->setWindowState( Qt::WindowMaximized );
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
	//TODO: Check file status
	QCoreApplication::quit();
}

void MainWindow::about() {

}
