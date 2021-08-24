#include <QApplication>
#include <QMessageBox>
#include <QSysInfo>
#include <QScreen>
#include <QDebug>


QString english{
    "The quick brown fox jumps over the lazy dog."
};
QString chinese{
    "我能吞下玻璃而不伤身体。"
};
QString japanese{
    "いろはにほへと / ちりぬるを / わかよたれそ / つねならむ / うゐのおくやま / けふこえて / あさきゆめみし / ゑひもせす"
};
QString korean{
    "키스의 고유조건은 입술끼리 만나야 하고 특별한 기술은 필요치 않다."
};

QString sentences = QString{"%1\n%2\n%3\n%4"}.arg(english, chinese, japanese, korean);


int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) || defined(Q_OS_LINUX)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QString text = QString{
                                                                                        "%1\n"
                    "QApplication::font().pointSize(): "                                "%2, "
                    "family(): "                                                        "%3\n"
                    "QSysInfo::buildAbi(): "                                            "%4\n"
                    "QSysInfo::kernelType(): "                                          "%5, "
                              "kernelVersion(): "                                       "%6\n"
                    "QSysInfo::prettyProductName(): "                                   "%7\n"
                    "QGuiApplication::primaryScreen()->geometry().width(): "            "%8, "
                                                                 "height(): "           "%9\n"
                    "QGuiApplication::primaryScreen()->physicalSize().width(): "        "%10, "
                                                                     "height(): "       "%11\n"
                    "QGuiApplication::primaryScreen()->physicalDotsPerInch(): "         "%12, "
                                                      "X(): "                           "%13, "
                                                      "Y(): "                           "%14\n"
                    "QGuiApplication::primaryScreen()->logicalDotsPerInch(): "          "%15, "
                                                      "X(): "                           "%16, "
                                                      "Y(): "                           "%17\n"
                    "QGuiApplication::primaryScreen()->devicePixelRatio(): "            "%18\n"
                    "QGuiApplication::primaryScreen()->availableGeometry().width(): "   "%19, "
                                                                          "height(): "  "%20\n"
                    "QGuiApplication::primaryScreen()->refreshRate(): "                 "%21"
                }
                .arg(
                    sentences,
                    QString::number(QApplication::font().pointSize()),
                    QApplication::font().family(),
                    QSysInfo::buildAbi(),
                    QSysInfo::kernelType(),
                    QSysInfo::kernelVersion(),
                    QSysInfo::prettyProductName(),
                    QString::number(QGuiApplication::primaryScreen()->geometry().width()),
                    QString::number(QGuiApplication::primaryScreen()->geometry().height()),
                    QString::number(QGuiApplication::primaryScreen()->physicalSize().width()),
                    QString::number(QGuiApplication::primaryScreen()->physicalSize().height()),
                    QString::number(QGuiApplication::primaryScreen()->physicalDotsPerInch()),
                    QString::number(QGuiApplication::primaryScreen()->physicalDotsPerInchX()),
                    QString::number(QGuiApplication::primaryScreen()->physicalDotsPerInchY()),
                    QString::number(QGuiApplication::primaryScreen()->logicalDotsPerInch()),
                    QString::number(QGuiApplication::primaryScreen()->logicalDotsPerInchX()),
                    QString::number(QGuiApplication::primaryScreen()->logicalDotsPerInchY()),
                    QString::number(QGuiApplication::primaryScreen()->devicePixelRatio()),
                    QString::number(QGuiApplication::primaryScreen()->availableGeometry().width()),
                    QString::number(QGuiApplication::primaryScreen()->availableGeometry().height()),
                    QString::number(QGuiApplication::primaryScreen()->refreshRate()));

    auto testLines = text.split('\n');

    for(const QString &testLine: qAsConst(testLines)) {
        qDebug() << testLine;
    }

    // https://stackoverflow.com/questions/32589776/qmessagebox-you-can-select-text-from
    QMessageBox mb;
    mb.setTextInteractionFlags(
                Qt::TextInteractionFlag::TextSelectableByKeyboard | Qt::TextInteractionFlag::TextSelectableByMouse);

    mb.setText(text);
    mb.exec();

    return 0;
}
