CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare nHigh int;
    SET nHigh = N - 1;
  RETURN (            
        SELECT DISTINCT salary
        FROM employee
        ORDER BY salary DESC
        LIMIT nHigh, 1        
  );
END
