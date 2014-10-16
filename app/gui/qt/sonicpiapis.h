//--
// This file is part of Sonic Pi: http://sonic-pi.net
// Full project source: https://github.com/samaaron/sonic-pi
// License: https://github.com/samaaron/sonic-pi/blob/master/LICENSE.md
//
// Copyright 2013, 2014 by Sam Aaron (http://sam.aaron.name).
// All rights reserved.
//
// Permission is granted for use, copying, modification, distribution,
// and distribution of modified versions of this work as long as this
// notice is included.
//++


#include <Qsci/qsciabstractapis.h>
#include <QHash>

class SonicPiAPIs : public QsciAbstractAPIs
{
 public:
  enum { Func, FX, Synth, Sample, Chord, Scale,
	 NContext };

  SonicPiAPIs(QsciLexer *lexer);

  void addSymbol(int context, QString sym);
  void addKeyword(int context, QString keyword);
  void addFXArgs(QString fx, QStringList args);

  void loadSamples(QString sample_path);


  //! \reimp
  virtual void updateAutoCompletionList(const QStringList &context,
					QStringList &list);

  virtual QStringList callTips(const QStringList &context, int commas,
			       QsciScintilla::CallTipsStyle style,
			       QList<int> &shifts);
  
  
 private:
  QStringList keywords[NContext];
  QHash<QString, QStringList> fxArgs;
};
