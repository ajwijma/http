/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QtWebSockets/QWebSocket>

QT_BEGIN_NAMESPACE
class QSslError;
class QNetworkReply;
class QTimer;
QT_END_NAMESPACE

namespace Ui
{
    class Dialog;
}

class HttpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HttpWindow(QWidget *parent = 0);
    ~HttpWindow();

private slots:
    void onBetfairTimeout();
    void onPokerStarsTimeout();
    void downloadBetfairTennisHighlights();
    void downloadBetfairTennisMarkets();
    void httpBetfairTennisHighlightsFinished();
    void httpBetfairTennisMarketsFinished();
    void httpPokerStarsTennisHighlightsFinished();
    void httpPokerStarsRootLadderFinished();
    void sslErrors(QNetworkReply *, const QList<QSslError> &errors);
    void downloadPokerStars();
    void onConnected();
    void onTextFrameReceived(const QString &frame, bool last);
    void onTextMessageReceived(const QString &message);
    void onSslErrors(const QList<QSslError> &errors);
    void resizeWindow();
    void onError();
    void onColorTimeout();

private:
    void arbitrage();

    Ui::Dialog *ui;
    QString urlTennisHighlights;
    QString urlTennisMarketsBase;
    QString urlTennisMarkets;
    QString urlPokerStarsRootLadder;
    QString urlPokerStarsTennisHighlights;

    QUrl url;
    QNetworkAccessManager qnam;

    QNetworkReply *replyTennisHighlights;
    QList<QNetworkReply *>replyTennisMarkets;

    QNetworkReply *replyPokerStarsRootLadder;
    QNetworkReply *replyPokerStarsTennisHighlights;

    QStringList marketIds;

    QList<double> rootLadder;
    QStringList eventIds;

    QTimer *betfairTimer;
    int     m_iTennisHighlightsTimeout;
    int     m_iTennisMarketsTimeout;
    QTimer *pokerStarsTimer;
    QTimer *colorTimer;

    QWebSocket webSocket;

    int pokerStarsOffset;
};

#endif
