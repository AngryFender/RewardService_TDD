#ifndef REWARDSERVICE_H
#define REWARDSERVICE_H

#include <QObject>

enum list_subscriptions{
    CHANNEL_SPORTS,
    CHANNEL_KIDS,
    CHANNEL_MUSIC,
    CHANNEL_NEWS,
    CHANNEL_MOVIES
};

enum list_eligibility{
    CUSTOMER_ELIGIBLE,
    CUSTOMER_INELIGIBLE,
    TECHNICAL_FAILURE_EXCEPTION,
    INVALID_ACCOUNT_NUMBER_EXCEPTION
};

enum list_eligibleRewards{
    CHAMPIONS_LEAGUE_FINAL_TICKETS,
    NA,
    KARAOKE_PRO_MICROPHONE,
    PIRATES_OF_THE_CARRIBEAN_COLLECTION
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

    QString get_rewards()const{
        QString reward = "No rewards";
        switch (_eligibility) {
        case CUSTOMER_ELIGIBLE: reward = get_eligibleReward();break;
        case CUSTOMER_INELIGIBLE:;break;
        case TECHNICAL_FAILURE_EXCEPTION:;break;
        case INVALID_ACCOUNT_NUMBER_EXCEPTION:reward = "No rewards, the account number entered is invalid";break;
        }
        return reward;
    }

    friend class AccessRewardServ;

signals:
    void signal_send_accountNo( unsigned int accountNo) const;
public slots:
    void slot_accept_eligibility(list_eligibility eligibility){
        _eligibility = eligibility;
    }
private:
    QString get_eligibleReward()const{
        QString reward = "NA";
        switch (_subscription) {
        case CHANNEL_SPORTS:    reward = "Champions League Final Tickets";      break;
        case CHANNEL_KIDS:                                                      break;
        case CHANNEL_MUSIC:     reward = "Karaoke Pro Microphone";              break;
        case CHANNEL_NEWS:                                                      break;
        case CHANNEL_MOVIES:    reward = "Pirates of the Carribean Collection"; break;
        }
        return reward;
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
    list_eligibility showEligibility(const RewardService& rewardService) const{
        return rewardService._eligibility;
    }
};

#endif // REWARDSERVICE_H
