//#include <iostream>
//#include <vector>
//
//int main()
//{
//    size_t request_time;
//    std::vector<int> requests;
//    std::cin >> request_time;
//    for (size_t i = 0; i < request_time; i++) {
//        int number_requests;
//        std::cin >> number_requests;
//        requests.push_back(number_requests);
//    }
//    double smoothing_window;
//    std::cin >> smoothing_window;
//    int moving_average = 0;
//    for (size_t i = 0; i < smoothing_window; i++) {
//        moving_average += requests.at(i);
//    }
//    std::cout << moving_average / smoothing_window << " ";
//    for (size_t i = 1; i < request_time - smoothing_window + 1; i++) {
//        moving_average = moving_average - requests.at(i - 1) + requests.at(i + smoothing_window - 1);
//        std:: cout << moving_average / smoothing_window << " ";
//    }
//    return 0;
//}
