#include <QtTest>

// add necessary includes here

class RewardsTesting : public QObject
{
    Q_OBJECT

public:
    RewardsTesting();
    ~RewardsTesting();

private slots:
    void test_case1();

};

RewardsTesting::RewardsTesting()
{

}

RewardsTesting::~RewardsTesting()
{

}

void RewardsTesting::test_case1()
{

}

QTEST_APPLESS_MAIN(RewardsTesting)

#include "tst_rewardstesting.moc"
