#include <YSI_Coding\y_hooks>

hook OnMySQLConnected()
{
    static const query[] = "\
        CREATE TABLE IF NOT EXISTS weapons \
        (\
            u_id int(11) NOT NULL AUTO_INCREMENT,\
            weapid int(11) NOT NULL,\
            ammo int(30) NOT NULL,\
            UNIQUE KEY (u_id, weapid), \
            FOREIGN KEY (u_id) REFERENCES players(u_id) \
            ON DELETE CASCADE \
            ON UPDATE RESTRICT \
        )";
    mysql_tquery(MySQL_GetHandle(), query);

    log("setting up 'weapons' table...");
    return 1;
}   