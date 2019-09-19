#ifndef MOCK_ELIGIBILITYSERVICE_H
#define MOCK_ELIGIBILITYSERVICE_H

#include <QObject>

class Mock_EligibilityService : public QObject
{
    Q_OBJECT
    unsigned int _accountNo;
public:
    explicit Mock_EligibilityService(QObject *parent = nullptr);
    ~Mock_EligibilityService();

    friend class Access_mock_Eligibility;
signals:

public slots:
    void slot_accept_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }
};


class Access_mock_Eligibility
{
public:
    unsigned int get_accountNo(const Mock_EligibilityService& mock)const{
        return mock._accountNo;
    }
};



#endif // MOCK_ELIGIBILITYSERVICE_H
