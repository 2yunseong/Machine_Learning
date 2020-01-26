#include <iostream>
#define MAX2(a, b) (a) > (b) ? (a) : (b)
using namespace std;

class Neuron
{
public:
    double weight; //weight of input
    double bias;   //bias

    double input_, output_; //save for back-propagation
    double getActivation(const double &y)
    {
        //get activation functions value.
        //for linear or identity activation functions
        return y;

        //for ReLU activation functions
        //return MAX2(0.0, x)
    }
    double feedForward(const double &param_input)
    {
        //output y = f(\sigma)
        //sigma = weight * x + bias
        input_ = param_input; //x
        const double sigma = weight * input_ + bias;
        output_ = getActivation(sigma); //y

        cout<<"input value :"<<input_<<"    output value : "<<output_<<endl;
        return output_;
    }
    double GetActivationGrad(const double &x)
    {
        /* df / dsigma */
        //for linear or identity activation functions
        return 1.0;

        //for ReLU activation functions
        //return MAX2(0.0, x)
    }

    double propBackward(const double &target)
    {
        const double alpha = 0.1;                                                  //learning rate.
        const double grad = (output_ - target) * 1.0 * GetActivationGrad(output_); // dE / dw
        weight -= alpha * grad * input_;    //last input came from d(wx+b)/dw = x = input_
        bias -= alpha * grad * 1.0;     //last 1.0 came from d(wx+b)/db = 1.0 (constant)
    }

    void ShowData() const
    {
        cout<<"weight:"<<weight<<"    bias:"<<bias<<endl;
    }
};

int main()
{
    Neuron my_neuron;
    double answer =4 ;
    my_neuron.bias = 1.0;
    my_neuron.weight = 2.0;

    for(int i=0; i<70; i++)
    {
        cout<<"Train count:"<<i<<endl;
        my_neuron.feedForward(1.0);
        my_neuron.propBackward(answer);
        my_neuron.ShowData();
    }

    return 0;
}
