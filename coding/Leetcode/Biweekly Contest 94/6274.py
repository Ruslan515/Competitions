# https://leetcode.com/contest/biweekly-contest-94/problems/reward-top-k-students/
from typing import List

class Solution:
    def topStudents(
            self,
            positive_feedback: List[str],
            negative_feedback: List[str],
            report: List[str],
            student_id: List[int],
            k: int
    ) -> List[int]:
        answer = []

        p = set(positive_feedback)
        n = set(negative_feedback)
        for i, rep in enumerate(report):
            point = 0
            rrr = rep.split(" ")
            for word in rrr:
                if word in p:
                    point += 3
                elif word in n:
                    point -= 1

            answer.append((-point, student_id[i]))
        answer.sort()
        answer = [v for k, v in answer]
        answer = answer[:k]

        return answer


def read_data():
    # positive_feedback = ["smart", "brilliant", "studious"]
    # negative_feedback = ["not"]
    # report = ["this student is not studious","the student is smart"]
    # student_id = [1, 2]
    # k = 2

    # positive_feedback = ["fkeofjpc", "qq", "iio"]
    # negative_feedback = ["jdh", "khj", "eget", "rjstbhe", "yzyoatfyx", "wlinrrgcm"]
    # report = [
    #     "rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio",
    #     "gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx",
    #     "tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe",
    #     "jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh",
    #     "yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq",
    #     "fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v",
    #     "wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq",
    #     "d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe"
    # ]
    # student_id =  [96537918, 589204657, 765963609, 613766496, 43871615, 189209587, 239084671, 908938263]
    # k = 3

    positive_feedback = ["m", "eveszfubew"]
    negative_feedback = ["iq", "etwuedg", "egpakyk", "da", "qkmhvgxg", "q", "zs", "ujmy", "mh"]
    report = [
        "eveszfubew jebebqp iq eveszfubew eveszfubew iq daej eveszfubew q da",
        "ohfz zs ujmy egpakyk eveszfubew pffeq q qkmhvgxg kdgqq ipp",
        "cceierguau mh da eveszfubew m etwuedg ikeft egpakyk ltnibxljfi m",
        "km m iq rab inooo ujmy tlrdyu yqhn m xlkhebs",
        "q etwuedg m eveszfubew ixrfzwmb m jyltumdwt dacmewk odbllqdiq eveszfubew"
    ]
    student_id =  [643903773, 468275834, 993893529, 509587004, 61125507]
    k = 5
    # Output:
    # [61125507, 509587004, 993893529, 643903773, 468275834]
    # Expected:
    # [61125507, 643903773, 993893529, 509587004, 468275834]

    return positive_feedback, negative_feedback, report, student_id, k

def main():
    positive_feedback, negative_feedback, report, student_id, k = read_data()
    sol = Solution()
    print(sol.topStudents(positive_feedback, negative_feedback, report, student_id, k))

if __name__ == "__main__":
    main()
