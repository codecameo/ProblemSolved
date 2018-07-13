#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std ;

string solve( priority_queue<int> & god , priority_queue<int> & mecha ) {
    bool g = true ;

    while( true ) {
        if( god.empty() ) {
            g = false ;
            break ;
        }

        if( mecha.empty() ) {
            break ;
        }

        int fg = -god.top() ;
        int fm = -mecha.top() ;

        if( fg == fm || fg > fm ) {
            mecha.pop() ;
        }

        else god.pop() ;
    }

    if( g ) return "Godzilla" ;
    return "MechaGodzilla" ;
}

int main() {

    int T ;

    cin >> T ;

    int NG , NM ;

    for( int i = 0 ; i < T ; i ++ ) {
        scanf("%d %d",&NG,&NM) ;
        priority_queue<int> god ;
        priority_queue<int> mecha ;

        int power ;

        for( int j = 0 ; j < NG ; j ++ ) {
            scanf("%d",&power) ;
            god.push( -power ) ;
        }

        for( int j = 0 ; j < NM ; j ++ ) {
            scanf("%d",&power) ;
            mecha.push( -power ) ;
        }

        string res = solve( god , mecha ) ;
        cout << res << "\n" ;
    }

    return 0 ;
}
