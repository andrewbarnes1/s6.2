#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>

DigitalOut red(LED1,1);
void flash(void){
    red = !red;
}
DigitalOut green(LED2,1);
void blink(void){
    green = !green;
}

Serial pc(USBTX, USBRX);
// This thread will run the event queues dispatch funciton
Thread worker;
EventQueue queue ; // Creates a queue to hold events

Thread thread;

int main() {
    pc.printf("ready");
    queue.call_every(500, flash); // Add to the event queue
    queue.call_every(300, blink);
    pc.printf("dispatching...");
    queue.dispatch_forever();
    // This starts the event queues dispatch thread.
    //worker.start(callback(&queue, &EventQueue::dispatch_forever ));
    pc.printf("dispatched");
    while(1){}
}
