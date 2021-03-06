#include "globalobserver.h"


GlobalObserver* GlobalObserver::m_pInstance = nullptr;

GlobalObserver::GlobalObserver()
{
}
GlobalObserver::~GlobalObserver()
{
}

GlobalObserver* GlobalObserver::GetInstance()
{
    if (m_pInstance == nullptr) {
        m_pInstance = new GlobalObserver();
    }
    return m_pInstance;
}

void GlobalObserver::attach(const QString type, QObject* receiver, const char *method)
{
    obesrverApater* oa = new obesrverApater();
    connect(oa, SIGNAL(notify()), receiver, method);
    relationData *data = new relationData();
    data->type = type;
    data->receiver = receiver;
    data->obesrverApater = oa;
    m_oRelationList.append(data);
}

void GlobalObserver::detach(const QString  type, const QObject * receiver)
{
    QList<relationData*>::iterator iter = m_oRelationList.begin();

    while (iter != m_oRelationList.end()){
        if ((*iter)->type.compare(type) == 0 && (*iter)->receiver == receiver){
            relationData *data = *iter;
            m_oRelationList.removeOne((*iter));
            delete data->obesrverApater;
            delete data;
            return;
        }
        iter++;
    }
}

void GlobalObserver::notify(const QString  type)
{
    QList<relationData*>::iterator iter = m_oRelationList.begin();
    while (iter != m_oRelationList.end()){
        if ((*iter)->type.compare(type) == 0){
            emit(*iter)->obesrverApater->notify();
        }
        iter++;
    }
}
