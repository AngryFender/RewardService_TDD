#include <QtTest>
#include "rewardservice.h"

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
