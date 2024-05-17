
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iniparser.h>

// Data structure for user information
struct user_data {
    char* first_name;
    char* last_name;
    int birth_year;
};

// Data structure for configuration
struct user_data {
    struct user_data* users;
    size_t num_users;
    char* listen_hostname;
    int listen_port;
    double connection_ratio;
};

int dataParse(dictionary* ini, const char* key, struct user_data* user) {
    user->first_name = iniparser_getstring(ini, key, "first_name", NULL);
    user->last_name = iniparser_getstring(ini, key, "last_name", NULL);
    user->birth_year = iniparser_getint(ini, key, "birth_year", -1);

    if (!user->first_name || !user->last_name || user->birth_year == -1) {
        return 0;
    }

    return 1; 
}

int parse_user_data(const char* filename, const char* key, struct user_data* cfg) {
    dictionary* ini = iniparser_load(filename);
    if (!ini) {
        return 0; 
    }
    cfg->listen_hostname = iniparser_getstring(ini, key, "listen_hostname", NULL);
    cfg->listen_port = iniparser_getint(ini, key, "listen_port", -1);
    cfg->connection_ratio = iniparser_getdouble(ini, key, "connection_ratio", -1.0);

    cfg->num_users = iniparser_getsecnkeys(ini, key);
    cfg->users = (struct user_data*)malloc(cfg->num_users * sizeof(struct user_data));
    assert(cfg->users); 
    int success = 1;
    for (size_t i = 0; i < cfg->num_users; ++i) {
        const char* user_section = iniparser_getsecname(ini, i);
        success &= dataParse(ini, user_section, &cfg->users[i]);
    }

    iniparser_freedict(ini);
    return success;
}

int main() {
    struct config cfg;
    if (parse_user_data("config.ini", "cfg", &cfg)) {
        printf("Configuration parsed successfully!\n");
        // Access cfg.listen_hostname, cfg.listen_port, cfg.connection_ratio, and cfg.users
        // ...
    } else {
        printf("Failed to parse configuration.\n");
    }

    return 0;
}
```

Remember to adjust the code according to your specific needs and error handling requirements. Happy coding! 🚀