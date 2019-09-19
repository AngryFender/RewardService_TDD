#include <QtTest>
#include "rewardservice.h"
#include "mock_eligibilityservice.h"

class RewardsTesting : public QObject
{
    Q_OBJECT

public:
    RewardsTesting();
    ~RewardsTesting();

private slots:
    void test_accepts_account_number_subscription();
    void test_sends_account_number();
    void test_accepts_eligibility();

};

RewardsTesting::RewardsTesting()
{

}

RewardsTesting::~RewardsTesting()
{

}

void RewardsTesting::test_accepts_account_number_subscription()
{
    RewardService  rewardService;
    const AccessRewardServ accessRewardServ;

    rewardService.set_accountNo(123);
    QCOMPARE(accessRewardServ.showAccountNo(rewardService), 123);

    rewardService.set_subscription(CHANNEL_SPORTS);
    QCOMPARE(accessRewardServ.showSubscription(rewardService), CHANNEL_SPORTS);
}

void RewardsTesting::test_sends_account_number()
{
    RewardService  rewardService;
    rewardService.set_accountNo(123);

    Mock_EligibilityService mock_eligibility;
    connect(&rewardService,SIGNAL(signal_send_accountNo(unsigned int)), &mock_eligibility,SLOT(slot_accept_accountNo(unsigned int)));
    rewardService.send_accountNo();

    const Access_mock_Eligibility accessMockEligibility;

    QCOMPARE(accessMockEligibility.get_accountNo(mock_eligibility),123);
}

void RewardsTesting::test_accepts_eligibility()
{
    RewardService  rewardService;
    Mock_EligibilityService mock_eligibility;
    connect( &mock_eligibility,SIGNAL(signal_send_eligibility(unsigned int)),&rewardService,SLOT(slot_accept_eligibility(unsigned int)));

    Access_mock_Eligibility accessMockEligibility;
    accessMockEligibility.set_eligibility(mock_eligibility,3);

    mock_eligibility.send_eligibility();

    const AccessRewardServ accessRewardServ;
    QCOMPARE(accessRewardServ.showEligibility(rewardService),3);
}

QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
