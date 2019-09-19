#ifndef REWARDSERVICE_H
#define REWARDSERVICE_H

#include <QObject>

enum list_subscriptions{
    CHANNEL_SPORTS,
    CHANNEL_KIDS,
    CHANNEL_MUSIC,
    CHANNEL_NEWS,
    CHANNEL_MOVIES,
    CHANNEL_OUT_OF_RANGE,
};

enum list_eligibility{
    CUSTOMER_ELIGIBLE,
    CUSTOMER_INELIGIBLE,
    TECHNICAL_FAILURE_EXCEPTION,
    INVALID_ACCOUNT_NUMBER_EXCEPTION
};

class RewardService : public QObject
{
    Q_OBJECT
    unsigned int _accountNo;
    list_subscriptions _subscription;
    list_eligibility _eligibility;

public:
    explicit RewardService(QObject *parent = nullptr);
    ~RewardService();

    void set_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }

    void set_subscription(list_subscriptions subscription){
        _subscription = subscription;
    }

    void send_accountNo()const{
        emit signal_send_accountNo(_accountNo);
    }

    friend class AccessRewardServ;

signals:
    void signal_send_accountNo( unsigned int accountNo) const;
public slots:
    void slot_accept_eligibility(list_eligibility eligibility){
        _eligibility = eligibility;
    }
};


class AccessRewardServ{
public:
    unsigned int showAccountNo(const RewardService& rewardService)const{
        return rewardService._accountNo;
    }
    list_subscriptions showSubscription(const RewardService& rewardService)const {
        return rewardService._subscription;
    }
    unsigned int showEligibility(const RewardService& rewardService) const{
        return rewardService._eligibility;
    }
};

#endif // REWARDSERVICE_H
