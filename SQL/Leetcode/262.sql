-- https://leetcode.com/problems/trips-and-users/
select request_at as "Day",
   round(coalesce(sum(cancels), 0)/coalesce(sum(requests), 0)/1.0, 2) as "Cancellation Rate"
from
(
    select request_at, count(*) as cancels, 0 as requests
    from trips t
    join users uc on t.client_id = uc.users_id and 'No' = uc.banned and 'client' = uc.role
    join users ud on t.driver_id = ud.users_id and 'No' = ud.banned and 'driver' = ud.role
    where t.status in ('cancelled_by_driver', 'cancelled_by_client')
        and t.request_at between '2013-10-01' and '2013-10-03'
    group by request_at
    
    union all
    
    select request_at, 0 as cancels, count(*) as requests
    from trips t
    join users uc on t.client_id = uc.users_id and 'No' = uc.banned and 'client' = uc.role
    join users ud on t.driver_id = ud.users_id and 'No' = ud.banned and 'driver' = ud.role
    where t.request_at between '2013-10-01' and '2013-10-03'
    group by request_at
) main
group by request_at
