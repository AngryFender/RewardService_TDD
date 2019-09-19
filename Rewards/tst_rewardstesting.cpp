#include <QtTest>

class RewardService{
    unsigned int _accountNo;
    unsigned int _subscription;

public:
    void set_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }

    void set_subscription(unsigned int subscription){
        _subscription = subscription;
    }

    friend class AccessRewardServ;
};

class AccessRewardServ{
public:
    unsigned int showAccountNo(RewardService& rewardService){
        return rewardService._accountNo;
    }
    unsigned int showSubscription(RewardService& rewardService){
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
    AccessRewardServ accessRewardServ;

    rewardService.set_accountNo(123);
    QCOMPARE(accessRewardServ.showAccountNo(rewardService), 123);

    rewardService.set_subscription(1);
    QCOMPARE(accessRewardServ.showSubscription(rewardService), 1);
}

QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
