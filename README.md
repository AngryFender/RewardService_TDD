# RewardService_TDD

Example of TDD being used to create Reward Service class. Each behaviour of the ideal Reward Service class was taken into accounts to create tests. Then those tests were used to create the Reward Service Class.

### Prerequisites

Qt 5.13.1
Qt Creator 4.10.0

## Running the tests

The project itself is a Unit Test Project

### Break down of tests

There are seven tests. Each one to tests a behaviour of the Reward Service Class

1. void test_accepts_account_number_subscription();
2. void test_sends_account_number();
3. void test_accepts_eligibility();
4. void test_show_rewards_when_eligibile();
5. void test_show_rewards_when_ineligible();
6. void test_show_rewards_when_technical_failure_exception();
7. void test_show_rewards_when_invalid_account_number_exception();

Three more classes were created to test the Reward Service class
1. Access_RewardServ - a friend class to access private members of the Reward Service class
2. Mock_EligibilityService - a mock class which contains the business logic. Since this is a mock class, the behaviours of this class is kept to similar to the original and only the output is set directly
3. Access_mock_Eligibility - a friend class to access privates memember of the Mock_EligibilityService class.
