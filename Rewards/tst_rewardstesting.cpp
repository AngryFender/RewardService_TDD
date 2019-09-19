#include <QtTest>

enum list_subscriptions{
    CHANNEL_SPORTS,
    CHANNEL_KIDS,
    CHANNEL_MUSIC,
    CHANNEL_NEWS,
    CHANNEL_MOVIES,
    CHANNEL_OUT_OF_RANGE,
};

class RewardService{
    unsigned int _accountNo;
    list_subscriptions _subscription;

public:
    void set_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }

    void set_subscription(list_subscriptions subscription){
        _subscription = subscription;
    }

    friend class AccessRewardServ;
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

class RewardsTesting : public QObject
{
    Q_OBJECT

public:
    RewardsTesting();
    ~RewardsTesting();

private slots:
    void test_accepts_account_number_subscription();

};

RewardsTesting::RewardsTesting()
{

}

RewardsTesting::~RewardsTesting()
{

}

void RewardsTesting::test_accepts_account_number_subscription()
{
    RewardService   rewardService;
    const AccessRewardServ accessRewardServ;

    rewardService.set_accountNo(123);
    QCOMPARE(accessRewardServ.showAccountNo(rewardService), 123);

    rewardService.set_subscription(CHANNEL_SPORTS);
    QCOMPARE(accessRewardServ.showSubscription(rewardService), CHANNEL_SPORTS);
}

QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
