/***************************************
 * signatureScan.cpp
 * Defines the Class declared in signatureScan.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Scan entire file looking for certain
 *           indicative signatures and report back.
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: when/if you add more pairs to signatureList
 *          UPDATE numSigs!!
 **************************************/

#include "signatureScan.h"
#include <QVBoxLayout>
#include <QString>

SignatureScan::SignatureScan()
{
    textOutput = new QTextEdit;
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( textOutput );
    setLayout( layout );
}

void SignatureScan::clean()
{
	textOutput->clear();
}
void SignatureScan::analysis(char * fileString, size_t fileSize, QProgressBar * pb)
{
	const int numSigs = 12; //Remember to change this
	QString signatureList[numSigs][2] = {{"DOS mode","PE"},
		{"ELF","ELF"}, {"ustar.00","TAR"},
		{"fLaC","Flac"},{"BM","Bitmap"},
		{"\xD0\xCF\x11\xE0\xA1\xB1\x1A\xE1","DOC"},
		{"%PDF","PDF"},{"\xFF\xFE\x00\x00","32 Bit UTF encoded Text"},
		{"\x52\x61\x72\x21\x1A\x07","RAR"},{"BZh","Bzip"},
		{"\x50\x4B\x03\x04\x14\x00\x08\x00\x08\x00","Java ByteCode"},{"\xFF\xD8","Jpeg"}};
	QString searchString = QString::fromLocal8Bit( fileString, fileSize );
	for (unsigned int counter = 0; counter < numSigs; counter++)
	{
		pb->setValue(pb->value() + (counter / numSigs * 100));
		if (searchString.contains(signatureList[counter][0]))
			textOutput->append("Possibly a " + signatureList[counter][1] +
				" file, signature \"" + signatureList[counter][0] + "\" found\n");
	}
	pb->setValue(100);
}
