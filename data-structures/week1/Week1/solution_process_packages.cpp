#include <iostream>
#include <queue>
#include <vector>

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};
static int b_size;

std::queue <int> process_time_;
//std::queue <int> finish_time_;

class Buffer {
public:
    Buffer(int size):
        size_(size)
       // process_time_(process_time_)
    {}

    Response Process(const Request &request) {
        // write your code here
    	struct Response response(false, 0);
    	//printf("finish time is : %d\n", process_time_.size() );
    	while (process_time_.size() && process_time_.front() <= request.arrival_time)
    	{
    		//size -= this->process_time_.front();
    		process_time_.pop();
    		if (this->size_ < b_size)
    		{
    			this->size_++;
    		}
    	}
    	if (this->size_)
    	{
			this->size_--;
			// 3 conditions
			// but 2 are same
			// process_time_.size() && request.arrival_time > process_time_.front() == else (first packet arrived)
			if (process_time_.size() && request.arrival_time < process_time_.front())
			{
				response.start_time = process_time_.back();
				//process_time_.push(request.process_time);
			}
			else {
				response.start_time = request.arrival_time;
			//	process_time_.push(request.process_time);
			}
			process_time_.push(response.start_time + request.process_time);
			response.dropped = 0;
    	}
    	else
    	    		response.dropped = 1;
   /* 	else if (process_time_.size() && request.arrival_time > process_time_.front())
    	{
    		if (process_time_.size() && this->size_ > process_time_.size() && process_time_.front() > request.arrival_time)
    		{
    			response.start_time = request.arrival_time;

    		process_time_.push(request.process_time);
    		response.dropped = 0;
    		}
    	}*/

    	return response;
    }
private:
    int size_;

};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
  // count = 6;
    //requests.push_back(Request(0, 2));
   // requests.push_back(Request(1, 2));
    //requests.push_back(Request(2, 2));
   // requests.push_back(Request(3, 2));
   // requests.push_back(Request(4, 2));
  //  requests.push_back(Request(5, 2));
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (unsigned int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (unsigned int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
   std::cin >> size;
   // size = 3;
    b_size = size;
    std::queue <int> finish_time;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
