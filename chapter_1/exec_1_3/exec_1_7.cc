/*
 * comment pairs /* */ cannot nest.
 * "cannot nest" is considered source code,
 * as is the rest of the program
 */

//[g++ reported] error: ‘cannot’ does not name a type
    int main()
{
    return 0;
}
