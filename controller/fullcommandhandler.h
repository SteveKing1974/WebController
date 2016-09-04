#ifndef FULLCOMMANDHANDLER_H
#define FULLCOMMANDHANDLER_H

#include "commandhandler.h"

#include "panelboard.h"
#include "interlockhandling.h"

#include <QJsonObject>

class FullCommandHandler : public CommandHandler
{
public:
    FullCommandHandler(HardwareController* pControl, PanelBoard *pPanel, InterlockHandling* pInterlock);

    QByteArray getCommand(const QByteArray& url) const;
    QByteArray putCommand(const QByteArray& url, const QByteArray& data) const;

private:
    HardwareController* m_pController;
    PanelBoard* m_pPanel;
    InterlockHandling* m_pInterlock;
    QJsonObject getPanelData() const;
    QJsonObject getControllerData() const;
};

#endif // FULLCOMMANDHANDLER_H
