#ifndef MOCK_ELIGIBILITYSERVICE_H
#define MOCK_ELIGIBILITYSERVICE_H
#include "rewardservice.h"
#include <QObject>

class Mock_EligibilityService : public QObject
{
    Q_OBJECT
    unsigned int _accountNo;
    list_eligibility _eligibility;
public:
    explicit Mock_EligibilityService(QObject *parent = nullptr);
    ~Mock_EligibilityService();

    void send_eligibility()const{
        emit signal_send_eligibility(_eligibility);
    }
    friend class Access_mock_Eligibility;
signals:
    void signal_send_eligibility(list_eligibility eligibility) const;

public slots:
    void slot_accept_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }
private:
    void set_eligibility(list_eligibility eligibility){
        _eligibility = eligibility;
    }
};


class Access_mock_Eligibility
{
public:
    unsigned int get_accountNo(const Mock_EligibilityService& mock)const{
        return mock._accountNo;
    }
    void set_eligibility(Mock_EligibilityService& mock,list_eligibility eligibility){
        mock.set_eligibility(eligibility);
    }
};



#endif // MOCK_ELIGIBILITYSERVICE_H
