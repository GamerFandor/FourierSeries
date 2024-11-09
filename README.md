## Explanations of each wave
### Sine Wave
$$u(t)=A*sin\left(\frac{2\pi}{T}t+\varphi\right)$$

---

### Square Wave
$$u(t) = \begin{cases} 
      V_1, & \text{if } 0 \leq t < \frac{DT}{100} \\
      V_2, & \text{if } \frac{DT}{100} \leq t < T 
   \end{cases}$$
$$a_0=\frac{1}{T}\left(\int_{0}^{\frac{DT}{100}}V_1dt+\int_{\frac{DT}{100}}^{T}V_2dt\right)=V_1\frac{D}{100}+V_2\left(1-\frac{D}{100}\right)$$
$$a_n=\frac{2}{T}\left(\int_{0}^{\frac{DT}{100}}V_1 * cos\left(\frac{2n\pi}{T}t\right)dt+\int_{\frac{DT}{100}}^{T}V_2 * cos\left(\frac{2n\pi}{T}t\right)dt\right)=\frac{2}{T}\left(V_1\frac{sin\left(\frac{Dn\pi}{50}\right)}{\frac{2n\pi}{T}}+V_2\frac{sin\left(2n\pi\right)-sin\left(\frac{Dn\pi}{50}\right)}{\frac{2n\pi}{T}}\right)$$
$$b_n=\frac{2}{T}\left(\int_{0}^{\frac{DT}{100}}V_1 * sin\left(\frac{2n\pi}{T}t\right)dt+\int_{\frac{DT}{100}}^{T}V_2 * sin\left(\frac{2n\pi}{T}t\right)dt\right)=\frac{2}{T}\left(V_1\frac{1-cos\left(\frac{Dn\pi}{50}\right)}{\frac{2n\pi}{T}}+V_2\frac{cos\left(\frac{Dn\pi}{50}\right)-cos\left(2n\pi\right)}{\frac{2n\pi}{T}}\right)$$
$$A_n=\sqrt{{a_n}^2+{b_n}^2}$$
$$\phi_n=atan2(b_n, a_n)+n\varphi$$
$$u(t)=a_0+\sum_{n=1}^{\infty}A_n*cos\left(\frac{2n\pi}{T}t-\phi_n\right)$$

---
