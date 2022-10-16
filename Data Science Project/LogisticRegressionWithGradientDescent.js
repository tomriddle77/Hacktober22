import math from "mathjs";
import csvToMatrix from "csv-to-array-matrix";

csvToMatrix("./src/data.csv", init);

function init(matrix) {
  // Part 0: Preparation
  console.log("Part 0: Preparation ...\n");

  let X = math.eval("matrix[:, 1:2]", {
    matrix,
  });
  let y = math.eval("matrix[:, 3]", {
    matrix,
  });

  let m = y.length;
  let n = X[0].length;

  // Part 1: Cost Function and Gradient
  console.log("Part 1: Cost Function and Gradient ...\n");

  // Add Intercept Term
  X = math.concat(math.ones([m, 1]).valueOf(), X);

  let theta = Array(n + 1)
    .fill()
    .map(() => [0]);
  let { cost: untrainedThetaCost, grad } = costFunction(theta, X, y);

  console.log("cost: ", untrainedThetaCost);
  console.log("\n");
  console.log("grad: ", grad);
  console.log("\n");

  // Part 2: Gradient Descent (without feature scaling)
  console.log("Part 2: Gradient Descent ...\n");

  const ALPHA = 0.001;
  const ITERATIONS = 400;

  theta = [[-25], [0], [0]];
  theta = gradientDescent(X, y, theta, ALPHA, ITERATIONS);

  const { cost: trainedThetaCost } = costFunction(theta, X, y);

  console.log("theta: ", theta);
  console.log("\n");
  console.log("cost: ", trainedThetaCost);
  console.log("\n");

  // Part 3: Predict admission of a student with exam scores 45 and 85
  console.log("Part 3: Admission Prediction ...\n");

  let studentVector = [1, 45, 85];
  let prob = sigmoid(
    math.eval("studentVector * theta", {
      studentVector,
      theta,
    })
  );

  console.log(
    "Predicted admission for student with scores 45 and 85 in exams: ",
    prob
  );
}

function sigmoid(z) {
  let g = math.eval(`1 ./ (1 + e.^-z)`, {
    z,
  });

  return g;
}

function costFunction(theta, X, y) {
  const m = y.length;

  let h = sigmoid(
    math.eval(`X * theta`, {
      X,
      theta,
    })
  );

  const cost = math.eval(`(1 / m) * (-y' * log(h) - (1 - y)' * log(1 - h))`, {
    h,
    y,
    m,
  });

  const grad = math.eval(`(1 / m) * (h - y)' * X`, {
    h,
    y,
    m,
    X,
  });

  return { cost, grad };
}

function gradientDescent(X, y, theta, ALPHA, ITERATIONS) {
  const m = y.length;

  for (let i = 0; i < ITERATIONS; i++) {
    let h = sigmoid(
      math.eval(`X * theta`, {
        X,
        theta,
      })
    );

    theta = math.eval(`theta - ALPHA / m * ((h - y)' * X)'`, {
      theta,
      ALPHA,
      m,
      X,
      y,
      h,
    });
  }

  return theta;
}

function predict(theta, X) {
  let p = sigmoid(
    math.eval(`X * theta`, {
      X,
      theta,
    })
  );

  return p;
}
