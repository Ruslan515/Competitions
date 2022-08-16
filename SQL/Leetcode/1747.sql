-- https://leetcode.com/problems/leetflex-banned-accounts/
# Write your MySQL query statement below
with t1 as (
    select
        l.account_id as account_id_1,
        l.ip_address as ip_address_1,
        l.login as login_1,
        l.logout as logout_1,
        l1.account_id as account_id_2,
        l1.ip_address as ip_address_2,
        l1.login as login_2,
        l1.logout as logout_2
    from LogInfo l join LogInfo l1 on l.account_id = l1.account_id
                                          and not(l.login = l1.login and l.logout = l1.logout)
),
    t2 as (
        select
            distinct account_id_1 as account_id
        from t1
        where (login_1 >= login_2 and login_1 <= logout_2 and ip_address_1 <> ip_address_2)
    )

select
    *
from t2
