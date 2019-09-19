#include <QtTest>

class RewardService{
    unsigned int _accountNo;

public:
    void set_accountNo(unsigned int accountNo){
        _accountNo = accountNo;
    }

    friend class AccessRewardServ;
};

class AccessRewardServ{
public:
    unsigned int showAccountNo(RewardService& rewardService){
        return rewardService._accountNo;
    }
};

class RewardsTesting : public QObject
{
    Q_OBJECT

public:
    RewardsTesting();
    ~RewardsTesting();

private slots:
    void test_accepts_account_number();

};

RewardsTesting::RewardsTesting()
{

}

RewardsTesting::~RewardsTesting()
{

}

void RewardsTesting::test_accepts_account_number()
{
    RewardService   rewardService;
    rewardService.set_accountNo(123);

    AccessRewardServ accessRewardServ;
    QCOMPARE(accessRewardServ.showAccountNo(rewardService), 123);
}

QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
