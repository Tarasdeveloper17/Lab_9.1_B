#include "header.h"
#import <XCTest/XCTest.h>

@interface tst : XCTestCase

@end

@implementation tst


- (void)testExample {
    cout << "Enter N: ";
    int N;
    cin>>N;
    Student *p = new Student[N];
    double resultScore = AverangeScore(p, N);
    
    XCTAssertNotEqual(resultScore, -2);

}


@end
