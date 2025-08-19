# https://medium.com/@maravondra/mysql-in-docker-d7bb1e304473
docker run --name mysql -p 3306:3306 -v ~/mysql-data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=root123 -d mysql/mysql-server

docker run --name mysql -p 3306:3306 -e MYSQL_ROOT_PASSWORD=root123 -d mysql/mysql-server

docker run --name mysql -p 3306:3306 -d mysql/mysql-server

docker run --rm --name mysql -p 3306:3306 -v $(pwd)/mysql-data:/var/lib/mysql -e MYSQL_PASSWORD=root123 -e MYSQL_USER=test_user -d mysql

docker run --name=my_sql -e MYSQL_ROOT_PASSWORD=root123 -d -p 3306:3306 mysql/mysql-server
