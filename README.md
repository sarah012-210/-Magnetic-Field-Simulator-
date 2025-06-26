# 🔌 Magnetic Field & Current Calculator

This C++ console program allows users to perform various **magnetostatics** calculations, including:

- Magnetic field (`B`) for different conductor configurations
- Mutual force between two long parallel wires
- Electric current (`I`) based on magnetic field data

## 📌 Features

1. **Magnetic Field Calculations** for:
   - Finite wire
   - Infinite (long) wire
   - Semi-infinite wire
   - Circular arc
   - Solenoid
   - Toroid

2. **Mutual Force** between two parallel wires

3. **Current Calculation** based on magnetic field:
   - For all conductor types listed above

4. **Vector Field Composition**  
   Accumulates magnetic field vectors and computes net field in 3D space.

## 🛠️ How It Works

The program relies on **Biot-Savart law** and **Ampere’s Law** to compute:
- \( B = \frac{{\mu_0 I}}{{2\pi R}} \) for long wires
- \( B = \frac{{\mu_0 I}}{{4\pi R}}(\cos(\theta_1) - \cos(\theta_2)) \) for finite wires
- And similar equations adapted for arcs, solenoids, and toroids.

It uses a menu-driven input system to guide the user through different types of calculations.

## 🔁 Program Flow

```text
Start
└── Choose calculation type:
    ├── Magnetic Field
    │   ├── Choose conductor type
    │   ├── Input values
    │   └── Output field and direction
    ├── Mutual Force
    │   └── Input I1, I2, distance, length
    └── Current
        └── Based on B and geometry
└── Option to repeat
