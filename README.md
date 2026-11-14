# alfreezzz
College's programming fundamentals project

## Description
This is a simple DBMS (Database Management System) project about career readiness tracker.
Built with C.

## Features
List of commands:
1. `SUBMIT TO`
2. `CHANGE`
3. `REMOVE FROM`
4. `PRESENT FROM`
5. `HELP`
6. `EXIT`

This project consists of 8 tables:
1. `positions` {id, name, createdAt, updatedAt} 
2. `skills` {id, name, proficiency, createdAt, updatedAt}
3. `targets` {id, positionId, skillId, isSkilled, createdAt, updatedAt}
4. `organizations` {id, name, createdAt, updatedAt}
5. `certificates` {id, name, issuerId, startDate, endDate, credentialId, url createdAt, updatedAt} 
6. `experiences` {id, organizationId, positionId, startDate, endDate, createdAt, updatedAt}
7. `categories` {id, name, createdAt, updatedAt}
8. `projects` {id, name, url, finishedDate, categoryId createdAt, updatedAt}

## Project structures
- `header.h` - library
- `machine.c` - function and procedure
- `main` - main system

## Run the project
```bash
chcp.com 65001
gcc *.c -o main && ./main.exe
```

*Built with C.*
# c-career-readiness-tracker