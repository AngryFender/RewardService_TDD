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

class RewardService : public QObject
{
    Q_OBJECT
    unsigned int _accountNo;
    list_subscriptions _subscription;

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
};


class AccessRewardServ{
public:
    unsigned int showAccountNo(const RewardService& rewardService)const{
        return rewardService._accountNo;
    }
    list_subscriptions showSubscription(const RewardService& rewardService)const {
        return rewardService._subscription;
    }
};

#endif // REWARDSERVICE_H