#include <cstddef>
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

class LogisticRegressionElement
{
public:
LogisticRegressionElement(unsigned long argc,double* argv,bool output):
value(output),size(argc)
{
    parameters=new double[argc];
    for(int i=0;i<argc;i++)
    {
        parameters[i]=argv[i];
    }
}

LogisticRegressionElement():size(0),parameters(0),value(0)
{

}


~LogisticRegressionElement()
{
    if(parameters)
    {
        delete [] parameters;
    }
};

LogisticRegressionElement& operator=(const LogisticRegressionElement& e)
{
    if(this==&e)
        return *this;

    this->size=e.size;
    this->value=e.value;
    
    for(int i=0;i<e.size;i++)
    {
        parameters[i]=e.parameters[i];
    }

    return *this;
}

LogisticRegressionElement(const LogisticRegressionElement& e):
size(e.size),value(e.value)
{
    parameters=new double[e.size];
        for(int i=0;i<e.size;i++)
    {
        parameters[i]=e.parameters[i];
    }
}

friend ostream& operator<<(ostream& os ,const LogisticRegressionElement& e)
{
    os<<"[";
    for(int i=0;i<e.size;i++)
    {
        os<<e.parameters[i];
        if(i!=e.size-1)
        {
            os<<',';
        }
    }
    os<<" || "<<e.value<<"]\n";
    return os;
}

bool isDefault()
{
    return size==0;
};


private:
unsigned long size;
double* parameters;
bool value;


};




// Hypothesis function (sigmoid function)
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Cost function

double costFunction(const vector<vector<double>>& X, const vector<int>& y, const vector<double>& theta) {
    int m = X.size();
    double cost = 0.0;
    for (int i = 0; i < m; ++i) {
        double h = sigmoid(theta[0] * X[i][0] + theta[1] * X[i][1] + theta[2] * X[i][2]); // Hypothesis
        cost += -y[i] * log(h) - (1 - y[i]) * log(1 - h);
    }
    return cost / m;
}

/*double costFunction(const vector<LogisticRegressionElement>& X)
{
    int M=X.size();

}
*/

// Gradient descent to update parameters
vector<double> gradientDescent(const vector<vector<double>>& X, const vector<int>& y, vector<double> theta, double alpha, int iterations) {
    int m = X.size();
    for (int iter = 0; iter < iterations; ++iter) {
        double sum0 = 0.0, sum1 = 0.0, sum2 = 0.0;
        for (int i = 0; i < m; ++i) {
            double h = sigmoid(theta[0] * X[i][0] + theta[1] * X[i][1] + theta[2] * X[i][2]); // Hypothesis
            sum0 += (h - y[i]) * X[i][0];
            sum1 += (h - y[i]) * X[i][1];
            sum2 += (h - y[i]) * X[i][2];
        }
        theta[0] -= alpha * sum0 / m;
        theta[1] -= alpha * sum1 / m;
        theta[2] -= alpha * sum2 / m;
    }
    return theta;
}

int main() {
    /*
    vector<vector<double>> X = {{1, 2, 1}, {1, 3, 1}, {1, 4, 1}, {1, 5, 1}}; // Features
    vector<int> y = {0, 0, 1, 1}; // Labels

    vector<double> theta = {0, 0, 0}; // Coefficients (including intercept term)

    double alpha = 0.01; // Learning rate
    int iterations = 1000; // Number of iterations

    theta = gradientDescent(X, y, theta, alpha, iterations);

    cout << "Trained Parameters: ";
    for (auto& t : theta) {
        cout << t << " ";
    }
    cout << endl;

    double prediction = sigmoid(theta[0] * 1 + theta[1] * 6 + theta[2] * 1);
    cout << "Prediction for (1, 6, 1): " << prediction << endl;
*/
 vector<LogisticRegressionElement> X;
 std::ifstream f("machine_failure.csv");
 string swap;

 double p[5];
 bool value;
 getline(f,swap);

int i=0;
 while(i<10000){
 f>>swap;
 f>>swap;
 f>>swap;
 for(int j=0;j<5;j++)
    f>>p[j];
 f>>value;
 getline(f,swap);
 X.push_back(LogisticRegressionElement(5,p,value));
  cout<<X[i];
 i++;

  }




    return 0;
}
