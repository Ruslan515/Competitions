-- https://leetcode.com/problems/highest-grade-for-each-student/
with t1 as (
    select
        student_id,
        max(grade) as max_grade
    from Enrollments
    group by student_id
),
    t2 as (
    select
        t1.*,
        e.course_id
    from t1 left join Enrollments e on (t1.max_grade = e.grade and t1.student_id = e.student_id)
    )
select
    student_id,
    min(course_id) as course_id,
    max_grade as grade
from t2
group by student_id, max_grade
order by student_id
