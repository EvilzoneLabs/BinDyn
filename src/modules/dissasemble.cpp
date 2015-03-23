/***************************************
 * dissasemble
 * Defines the Class declared in dissasemble.h
 * 
 * PreConditions: Program Started
 * Main Use: Very Limited Dissasembler.
 * 			 VERY Limited. 
 * 
 * PostCondtions: Dissasembly (hopefully) shown
 * 
 * Gotchas: None + not implemented yet
 **************************************/

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QString>
#include <QLabel>
#include <QSpacerItem>
#include "udis86/udis86.h"
#include "dissasemble.h"
#include <iostream>

Dissasemble::Dissasemble( )
{
	//Generate Arch SLider
		archSlider = new QSlider(Qt::Horizontal, this);
        archSlider->setRange(0, 4);
        QSpacerItem * leftSpacer = new QSpacerItem(width()/5,1);
        QSpacerItem * rightSpacer = new QSpacerItem(width()/5,1);
        QLabel *archLabel1 = new QLabel("IA-32", this);
        QLabel *archLabel2 = new QLabel("x86-64 ", this);
        QLabel *archLabel3 = new QLabel("MIPS", this);
        QLabel *archLabel4 = new QLabel("ARM", this);
        QLabel *archLabel5 = new QLabel("...JBC?", this);
        archLabel1-> setAlignment(Qt::AlignCenter);
        archLabel2-> setAlignment(Qt::AlignCenter);
        archLabel3-> setAlignment(Qt::AlignCenter);
        archLabel4-> setAlignment(Qt::AlignCenter);
        archLabel5-> setAlignment(Qt::AlignCenter);
        QHBoxLayout *archLayout = new QHBoxLayout;
        archLayout->addWidget(archLabel1);
        archLayout->addWidget(archLabel2);
        archLayout->addWidget(archLabel3);
        archLayout->addWidget(archLabel4);
        archLayout->addWidget(archLabel5);
        QVBoxLayout * mainLayout = new QVBoxLayout();
        QHBoxLayout * bottom = new QHBoxLayout();
        QHBoxLayout *sliderLayout = new QHBoxLayout;
        sliderLayout -> addSpacerItem(leftSpacer);
        sliderLayout -> addWidget(archSlider);
        sliderLayout -> addSpacerItem(rightSpacer);
        mainLayout -> addLayout(sliderLayout);
		mainLayout -> addLayout( archLayout );
		
	//generate Bottom	
		addresses = new QTextEdit();
		dissasembly = new QTextEdit();
		notes = new QTextEdit();
		bottom -> addWidget( addresses );
		bottom -> addWidget( dissasembly );
		bottom -> addWidget( notes );
		addresses -> setMaximumWidth(200);
		notes -> setMaximumWidth(300);
		mainLayout -> addLayout( bottom );
		setLayout( mainLayout );
	//Connect the Scrollbars
		QObject::connect(addresses -> verticalScrollBar(), SIGNAL(valueChanged(int)), dissasembly -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(addresses -> verticalScrollBar(), SIGNAL(valueChanged(int)), notes -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(dissasembly -> verticalScrollBar(), SIGNAL(valueChanged(int)), addresses -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(dissasembly -> verticalScrollBar(), SIGNAL(valueChanged(int)), notes -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(notes -> verticalScrollBar(), SIGNAL(valueChanged(int)), dissasembly -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(notes -> verticalScrollBar(), SIGNAL(valueChanged(int)), addresses -> verticalScrollBar(), SLOT(setValue(int)));
}

void Dissasemble::analysis( char * fileString, size_t fileSize, bool locality, QProgressBar * pb )
{
	int archChosen = 0;
	if (archSlider->value() < numArchs)
		archChosen = archSlider->value();
	switch (archChosen)
	{
		case(0):
			dis_x86(fileString,fileSize);
			break;
	}
}

void Dissasemble::clean()
{
	addresses -> clear();
	dissasembly -> clear();
	notes -> clear();
}

//Still slow no prgoress bare etc
void Dissasemble::dis_x86(char* data, size_t size)
{
	 ud_t u;
    
    ud_init(&u);
    ud_set_input_buffer(&u, reinterpret_cast<unsigned char *>(data), size);
    ud_set_mode(&u, 64);
    ud_set_syntax(&u, UD_SYN_INTEL);
    QString hexStr;
    QString dissasemblyStr;
    QString memory;
    while (ud_disassemble(&u)) {
		memory.append(QString::number(ud_insn_off(&u)) + '\n');
		dissasemblyStr.append(QString::fromLocal8Bit(ud_insn_asm(&u)) + '\n');
		hexStr.append(QString::fromLocal8Bit(ud_insn_hex(&u)) + '\n');
    }
    addresses -> setPlainText(memory);
	dissasembly -> setPlainText(dissasemblyStr);
	notes -> setPlainText(hexStr);
	
}
