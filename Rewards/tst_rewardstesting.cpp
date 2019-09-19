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
    void test_show_rewards_when_eligibile();
    void test_show_rewards_when_ineligible();
    void test_show_rewards_when_technical_failure_exception();
    void test_show_rewards_when_invalid_account_number_exception();

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
    connect( &mock_eligibility,SIGNAL(signal_send_eligibility(list_eligibility)),&rewardService,SLOT(slot_accept_eligibility(list_eligibility)));

    Access_mock_Eligibility accessMockEligibility;
    accessMockEligibility.set_eligibility(mock_eligibility,CUSTOMER_ELIGIBLE);

    mock_eligibility.send_eligibility();

    const AccessRewardServ accessRewardServ;
    QCOMPARE(accessRewardServ.showEligibility(rewardService),CUSTOMER_ELIGIBLE);
}

void RewardsTesting::test_show_rewards_when_eligibile()
{
    RewardService  rewardService;
    rewardService.set_subscription(CHANNEL_SPORTS);
    rewardService.slot_accept_eligibility(CUSTOMER_ELIGIBLE);

    QCOMPARE(rewardService.get_rewards(),"Champions League Final Tickets");
}

void RewardsTesting::test_show_rewards_when_ineligible()
{
    RewardService  rewardService;
    rewardService.slot_accept_eligibility(CUSTOMER_INELIGIBLE);

    QCOMPARE(rewardService.get_rewards(),"No rewards");
}

void RewardsTesting::test_show_rewards_when_technical_failure_exception()
{
    RewardService  rewardService;
    rewardService.slot_accept_eligibility(TECHNICAL_FAILURE_EXCEPTION);

    QCOMPARE(rewardService.get_rewards(),"No rewards");
}

void RewardsTesting::test_show_rewards_when_invalid_account_number_exception()
{
    RewardService  rewardService;
    rewardService.slot_accept_eligibility(INVALID_ACCOUNT_NUMBER_EXCEPTION);

    QCOMPARE(rewardService.get_rewards(),"No rewards, the account number entered is invalid");
}


QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
