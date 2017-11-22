import numpy as np

exp = np.exp 
log = np.log 
sin = np.sin 
cos = np.cos 
asin = np.arcsin 
acos = np.arccos 

class formulation():

    def __init__(self):

        self.n = 2 
        self.m = 3 

        self.F_inv = np.zeros((self.m,self.m)) 
        self.E = np.zeros((self.n,self.m)) 
        self.C = np.zeros((self.m,self.n)) 
        self.p = np.zeros((self.n,1)) 
        self.u = np.zeros((self.m,1)) 
        self.y = np.zeros((self.m,1)) 

        self.Q_1 = 0.1 
        self.V_2 = 1.0 
        self.theta_2 = 0.0 
        self.G_12 = 5.0 
        self.B_12 = 10.0 
        self.P_1 = 0.5 


        self.E_eval() 
        self.C_eval() 
        self.p_eval() 

    def E_eval(self):

        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        self.E[0,0]=G12 
        self.E[0,1]=-B_12 - G_12 
        self.E[1,0]=-B12 
        self.E[1,1]=B_12 
        self.E[1,2]=-G_12 


    def C_eval(self):

        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        self.C[0,0]=1 
        self.C[1,1]=1 


    def p_eval(self):

        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        self.p[0,0]=P_1 
        self.p[1,0]=Q_1 


    def f(self,y):

        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        y_1 = y[0,0] 
        y_2 = y[1,0] 
        y_3 = y[2,0] 

        return np.array([
                log(y_1),
                log(y_2**2 + y_3**2),
                atan(y_3/y_2)
                ]).reshape(self.m,1)
    def f_inv(self,u):

        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        u_1 = u[0,0] 
        u_2 = u[1,0] 
        u_3 = u[2,0] 

        return np.array([
                u_1,
                -sqrt(u_3**2*exp(u_2)),
                sqrt((-u_3**2 + 1)*exp(u_2))
                ]).reshape(self.m,1)

    def F_inv_eval(self,u):

        u_1 = u[0,0] 
        u_2 = u[1,0] 
        u_3 = u[2,0] 


        Q_1 = self.Q_1 
        V_2 = self.V_2 
        theta_2 = self.theta_2 
        G_12 = self.G_12 
        B_12 = self.B_12 
        P_1 = self.P_1 


        self.F_inv[0,0]=1 
        self.F_inv[1,1]=-sqrt(u_3**2*exp(u_2))/2 
        self.F_inv[1,2]=-sqrt(u_3**2*exp(u_2))/u_3 
        self.F_inv[2,1]=sqrt((-u_3**2 + 1)*exp(u_2))/2 
        self.F_inv[2,2]=-u_3*sqrt((-u_3**2 + 1)*exp(u_2))/(-u_3**2 + 1) 
    def a2x(self,a):

        a_1 = a[0,0] 
        a_2 = a[1,0] 


        V_1 = exp(a_1)**(1/2) 
        theta_1 = a_2+theta_2 


        return np.array([
            V_1,
            theta_1
            ]).reshape(self.n,1)

    def x2a(self,x):

        V_1 = x[0,0] 
        theta_1 = x[1,0] 


        a_0 = 2*log(V_1) 
        a_1 = theta_1-theta_2 


        return np.array([
            a_1,
            a_2
            ]).reshape(self.n,1)

